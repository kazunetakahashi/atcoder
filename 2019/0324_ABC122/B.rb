#
# File    : B.rb
# Author  : Kazune Takahashi
# Created : 2019-3-24 21:02:22
# Powered by Visual Studio Code
#

ans = 0
s = gets.chomp
ary = []
s.chars{|c|
  if ['A', 'C', 'G', 'T'].include?(c)
    ary << true
  else
    ary << false
  end
}
temp = 0
ary.each{|x|
  if x
    temp += 1
    ans = [ans, temp].max
  else
    temp = 0
  end
}
puts ans
