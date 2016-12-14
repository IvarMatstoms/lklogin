import urllib2
import urllib
username="username"
password="password"
url="https://surf.linkoping.se:6082/php/uid.php?vsys=1&url=http://google.se"
values={"inputStr":'',"user":"ivamat907","escapeUser":username,"passwd":password,"ok":"Login"}
data=urllib.urlencode(values)
req=urllib2.Request(url,data)
resp=urllib2.urlopen(req)
resptxt=resp.read()
