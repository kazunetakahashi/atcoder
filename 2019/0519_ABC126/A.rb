#
# File    : A.rb
# Author  : Kazune Takahashi
# Created : 5/19/2019, 8:46:54 PM
# Powered by Visual Studio Code
#

n, k = gets.chomp.split(" ").map{|i| i.to_i}
s = gets.chomp
s[k - 1] = s[k - 1].downcase
puts s
