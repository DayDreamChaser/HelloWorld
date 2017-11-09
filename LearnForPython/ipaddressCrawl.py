import requests
url = "http://m.ip138.com/ip.asp?ip="
ipaddr = '172.30.230.20'
try:
    r = requests.get(url + ipaddr)
    print(r.status_code)
    print(r.text[-500:])
except:
    print("Failed!")
