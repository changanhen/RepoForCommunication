from bs4 import BeautifulSoup
import re
import urllib.request
import sys
import sqlite3
url = "http://httpbin.org/post"
headers = {
    "Cookie" : "route=d80842f3ed8a3dae69abb1007cb767eb; cur_appId_=GRt5IN2Ni3M=; state=xjdCas; JSESSIONID=884BE73D86A7E91A43D7A666B3D7F332; sid_code=workbench_login_jcaptcha_884BE73D86A7E91A43D7A666B3D7F332; open_Platform_User=user_token_bf106336-0175-46bc-94a1-7d16639a9938; memberId=840404; usertypekey=1; employeenokey=2203612988",
    "User-Agent" : "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/93.0.4577.63 Safari/537.36 Edg/93.0.961.47",
    "name" : "2203612988",
    "password" : "2203612988"
}
# data = bytes(urllib.parse.urlencode({'name' : 'user_name'}), encoding="utf-8")
req = urllib.request.Request(url=url, headers=headers, method="POST")
response = urllib.request.urlopen(req)
print(response.read().decode("utf-8"))