#
# File    : B.rb
# Author  : Kazune Takahashi
# Created : 2018-11-4 21:02:12
# Powered by Visual Studio Code
#

n = gets.to_i
@t, a = gets.chomp.split(" ").map{|i| i.to_i}
h = gets.chomp.split(" ").map{|i| i.to_f}

def th(x)
  return @t - x * 0.006
end

ans = []

for i in 0...n do
  ans << [(a - th(h[i])).abs, i]
end

puts (ans.min)[1]

