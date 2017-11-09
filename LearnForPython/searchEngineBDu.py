import requests
keyword = "Python"
try:
    kv = {'wd':'python'}
    r = requests.get("https://www.baidu.com/s", params = kv)
    #r = requests.get("https://www.so.com/s", params = kv)
    print(r.request.url)
    r.raise_for_status()
    print(len(r.text))
except:
    print("Failed to crawl!")
