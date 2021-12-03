import os
import fcntl
import time

def readLines(path):
    with open(path, "r") as fp:
        stat = os.stat(path)
        fp.seek(stat[6])

        where = None

        fd   = fp.fileno()
        flag = fcntl.fcntl(fd, fcntl.F_GETFL)
        fcntl.fcntl(fd, fcntl.F_SETFL, flag | os.O_NONBLOCK)

        try:
            for last in fp:
                pass
        except IOError as e:
            if e.errno != 11:
                raise

        fcntl.fcntl(fd, fcntl.F_SETFL, flag)
        
        try:
            while True:
                where = fp.tell()
                line  = fp.readline()
                yield line
        except KeyboardInterrupt:
            pass

if __name__ == "__main__":
    import sys

    prefix = "memory size excessed: "
    for line in readLines("/dev/kmsg"):
        line = str(line)
        print(line)

        index = line.find(prefix)
        
        if index >= 0:
            pid = line[index+len(prefix):]
            pid = int(pid)
            print(pid)
            os.kill(int(pid), signal.SIGKILL)

            
