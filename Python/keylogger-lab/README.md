# keylogger-lab
 
A basic keylogger written in Python as a cybersecurity learning project. Built to understand how keystroke logging, file logging, and Windows registry persistence work under the hood.
 
## What it does
 
- Captures keystrokes using `pynput` and writes them to a log file
- Stores the log file in the user's AppData/home directory
- Adds itself to Windows startup via the registry so it persists across reboots
- Automatically installs `pynput` if not present
## Usage
 
```bash
python keylogger_lab.py
```
 
The program runs silently in the background. Keystrokes are logged to `keylogger_lab.log` in the user's AppData folder (Windows) or home directory (Linux).
 
## How it works
 
**Keystroke capture** — `pynput`'s `Listener` calls `on_press()` on every keypress. Special keys like space and enter are logged as readable characters; regular keys log their `.char` value; unknown special keys fall back to their string representation.
 
**Logging** — Python's built-in `logging` module writes to a file with automatic timestamps on each entry.
 
**Persistence** — On first run, the script adds itself to `HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Run` in the Windows registry. This causes it to launch automatically on user login. It checks first to avoid duplicate entries.
 
## Limitations
 
- Python processes are visible in Task Manager
- `pynput` is a known library — antivirus tools will flag this immediately
- `.py` scripts require Python to be installed on the target machine
- Not suitable as an actual security tool — this is purely educational
## What I learned
 
- How keyboard hooks work at the application level
- How Windows registry startup entries function
- How `winreg` interacts with the Windows registry from Python
- Error handling with `try/except` for both registry access and key parsing
- The difference between `__file__` and `sys.argv[0]` for script path resolution
## Legal notice
 
This tool is intended for educational purposes only. Only run it on machines you own or have explicit permission to monitor. The author is not responsible for any misuse.
 
## Environment
 
- Python 3.x
- Windows (registry persistence) / Linux (home directory fallback)
- Dependencies: `pynput` (auto-installed if missing)
