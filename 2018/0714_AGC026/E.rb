#
# File    : E.rb
# Author  : Kazune Takahashi
# Created : 2018-7-16 13:05:22
# Powered by Visual Studio Code
#

s = gets.chomp

ary = []
while !(s == "")
  a = 0
  b = 0
  for i in 0...s.size()
    if s[i] == "a"
      a += 1
    else
      b += 1
    end
    if a == b
      ary << s[0..i]
      s = s[i+1..-1]
      a = 0
      b = 0
      break
    end
  end
end

p ary
