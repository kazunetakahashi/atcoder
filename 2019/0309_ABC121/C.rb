#
# File    : C.rb
# Author  : Kazune Takahashi
# Created : 3/9/2019, 9:04:53 PM
# Powered by Visual Studio Code
#

n, m = gets.chomp.split(" ").map{|i| i.to_i}
ary = []
n.times{
  ary << gets.chomp.split(" ").map{|i| i.to_i}
}
ary = ary.sort_by{|a, b|
  b
}
ans = 0
m.times{
  if m < 100
    p ary
  end
  if ary[0][1] == 0
    ary.shift
  end
  ary[0][1] -= 1
  ans += ary[0][0]
}
puts ans
