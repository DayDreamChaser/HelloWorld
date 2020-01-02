import webbrowser
import time

web_str = "http://www.bing.com/"
print("started on" + time.ctime())
for x in range(3):
    time.sleep(10)
    print("My friend! Have a rest for a long time work!")
    webbrowser.open(web_str)
