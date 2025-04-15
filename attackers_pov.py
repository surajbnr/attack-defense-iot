import os
target="http://192.168.223.92/"
os.system(f"ab -n 1000 -c 100 -v 5 (target) >> output.txt")
print("Attack Successful")
