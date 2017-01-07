import sys
import urllib

username="username"
password="password"

url="https://surf.linkoping.se:6082/php/uid.php?vsys=1&url=http://google.se"
values={"inputStr":'',"user":username,"escapeUser":username,"passwd":password,"ok":"Login"}

if (sys.version_info > (3, 0)):
    import urllib.parse
    import urllib.request
    data = urllib.parse.urlencode(values).encode()
    req=urllib.request.Request(url,data)
    resp=urllib.request.urlopen(req)
    resptxt=resp.read()
    resp.close()
else:
    import urllib2
    data=urllib.urlencode(values)
    req=urllib2.Request(url,data)
    resp=urllib2.urlopen(req)
    resptxt=resp.read()
    resp.close()
