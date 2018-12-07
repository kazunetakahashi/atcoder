#
# File    : C.rb
# Author  : Kazune Takahashi
# Created : 12/7/2018, 10:08:13 PM
# Powered by Visual Studio Code
#

n = gets.to_i
ary = []
n.times{
  ary << gets.chomp.split(" ").map{|i| i.to_i}
}

takahashi = 1
aoki = 1

ary.each{|t, a|
  n = [(takahashi + t - 1)/t, (aoki + a - 1)/a].max
  takahashi = t * n
  aoki = a * n
}

puts takahashi + aoki