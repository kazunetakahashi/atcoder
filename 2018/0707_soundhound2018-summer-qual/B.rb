#
# File    : B.rb
# Author  : Kazune Takahashi
# Created : 2018-7-7 21:42:46
# Powered by Visual Studio Code
#

s = gets.chomp
w = gets.to_i
ind = 0
ans = ""
while ind < s.size
  ans += s[ind]
  ind += w
end
puts ans