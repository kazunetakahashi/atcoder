#
# File    : D.rb
# Author  : Kazune Takahashi
# Created : 12/6/2018, 11:13:54 PM
# Powered by Visual Studio Code
#

s = gets.chomp
ok = true
if s[0] == s[-1]
  ok = (s.size % 2 == 0)
else
  ok = (s.size % 2 == 1)
end

if ok
  puts "First"
else
  puts "Second"
end