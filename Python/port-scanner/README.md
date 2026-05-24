# port-scanner

A simple TCP port scanner written in Python. Built as a learning project while exploring network programming and cybersecurity basics.

## What it does

Takes a host and a port range as input, then attempts a TCP connection on each port. Reports which ports are open.

## Usage

```bash
python port_scanner.py
```

```
What host are we scanning?: scanme.nmap.org
Enter a scope: (ex.: 1 1024): 1 1024
Scanning scanme.nmap.org...
Port 22 is open.
Port 80 is open.
```

## How it works

Uses Python's built-in `socket` library to attempt a `connect_ex()` call on each port in the given range. If the call returns `0`, the port accepted the connection and is considered open. A 0.5s timeout is set per port to avoid hanging on filtered ports.

No external libraries required.

## Limitations

- Sequential scanning — ports are checked in order, which is easy for firewalls to detect
- TCP connect scan only — completes the full handshake, not stealthy
- Single-threaded — slow on large port ranges
- No service detection — just tells you a port is open, not what's running on it

This is an early-stage project. Future versions may include threading, randomized port order, and service banner grabbing.

## Legal notice

Only scan hosts you own or have explicit permission to scan. Unauthorized port scanning may be illegal in your jurisdiction. The author is not responsible for any misuse of this tool.

## Environment

- Python 3.x
- No external dependencies
