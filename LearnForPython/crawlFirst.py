import requests
url = "https://item.jd.com/2967929.html"
try:
    response = requests.get(url)
    response.raise_for_status()
    response.encoding = response.apparent_encoding
    print(response.text[:1000])
except:
    print("Failed for crawling")
    
