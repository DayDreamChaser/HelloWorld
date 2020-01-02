# Vertify the curse word or spam email(Machine Learning)
import requests

def read_text(path, file_name):
    quotes = open(path + file_name)
    text = quotes.read()
    print(text)
    quotes.close()
    
def check_profanity(text_to_check):
    response = requests.get("http://wwww.baidu.com/?q=" + text_to_check)
    output = response.text
    print(output)
    
# open the text file
win_path = "C:\\Users\\Administrator\\Desktop\\"
file_name = "movie_quotes.txt"
read_text(win_path, file_name)

check_profanity("fuck")


# 1 read the text line by line in a list


# 2 check the line to a set to check the curse words set
