#
# File    : C.rb
# Author  : Kazune Takahashi
# Created : 12/22/2018, 9:01:32 PM
# Powered by Visual Studio Code
#

require 'prime'

n, q = gets.chomp.split(" ").map{|i| i.to_i}
ans = 1
q.prime_division.each{|prime, m|
  ans *= prime ** (m/n)
}
puts ans
