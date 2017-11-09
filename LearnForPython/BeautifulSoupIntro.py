import requests
from bs4 import BeautifulSoup
r = requests.get("https://www.baidu.com")
demo = r.text
soup = BeautifulSoup(demo, 'html.parser')
print(soup.title)
print(soup.head)
soup.head.contents
soup.p.parent
