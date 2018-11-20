#
# File    : A.rb
# Author  : Kazune Takahashi
# Created : 11/20/2018, 11:16:27 PM
# Powered by Visual Studio Code
#

s = gets.chomp.split(" ").map{|i| i.to_s}

ans = ""

s.each{|str|
  ans += str[0].upcase
}

puts ans

