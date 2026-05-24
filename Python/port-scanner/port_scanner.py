import socket

host = input("What host are we scanning?: ")

port_scope = input("Enter a scope: (ex.: 1 1024): ").split()

start_port = int(port_scope[0])
end_port = int (port_scope[1])

print(f'Scanning {host}...')

for port in range(start_port, end_port + 1):
   s = socket.socket()
   s.settimeout(0.5)
   value = s.connect_ex((host, port))
   if value == 0:
       print(f'Port {port} is open.')
   s.close()
