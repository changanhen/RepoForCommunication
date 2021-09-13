import urllib.request
import urllib.parse
# Failure 405
'''
try:
    response = urllib.request.urlopen("http://httpbin.org/post")
    print(response.read().decode('utf-8'))
except Exception as result:
    print(result)
'''
data = bytes(urllib.parse.urlencode({"user_name":"password"}), encoding="utf-8")
response = urllib.request.urlopen("http://httpbin.org/post", data=data)
print(response.read().decode('utf-8'))