#
# File    : C.rb
# Author  : Kazune Takahashi
# Created : 2018-7-21 21:04:17
# Powered by Visual Studio Code
#

n = gets.to_i
a = gets.chomp.split(" ").map{|i| i.to_i}
ans = 0
a.each{|it|
  ans += it - 1
}
puts ans
