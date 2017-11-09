import requests
import os

url = "https://78.media.tumblr.com/2df76f5d206b955ad386d5e75c5571bb/tumblr_nhseczvOCb1tdonglo3_1280.jpg"
root = "F://"
def findPicture(url, root):
    path = root + url.split('/')[-1]
    # check the file name
    if not path[-4:-1] == '.jpg':
        path = path + '.jpg'
    try:
        #check whether the root is exist
        if not os.path.exists(root):
            os.mkdir(root)
        if not os.path.exists(path):
            r = requests.get(url)
            with open(path, 'wb') as f:
                f.write(r.content)
                f.close()
                print("Succeesfully reserve file!")
        else:
            print("File existed!")
    except:
        print("Failed to crawl!")

findPicture(url, root)
