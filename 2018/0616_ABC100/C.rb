#
# File    : C.rb
# Author  : Kazune Takahashi
# Created : 2018-6-16 21:04:56
# Powered by Visual Studio Code
#

n = gets.to_i
a = gets.chomp.split(" ").map{|u| u.to_i}

ans = 0

a.each{|n|
  while n % 2 == 0
    n /= 2
    ans += 1
  end
}

puts ans