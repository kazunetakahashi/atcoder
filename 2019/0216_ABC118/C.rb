#
# File    : C.rb
# Author  : Kazune Takahashi
# Created : 2/16/2019, 9:04:43 PM
# Powered by Visual Studio Code
#

n = gets.to_i
a = gets.chomp.split(" ").map{|i| i.to_i}
ans = a[0]
a.each{|x|
  ans = ans.gcd(x)
}
puts ans

