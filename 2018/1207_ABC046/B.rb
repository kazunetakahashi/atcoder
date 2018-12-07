#
# File    : B.rb
# Author  : Kazune Takahashi
# Created : 12/7/2018, 10:06:45 PM
# Powered by Visual Studio Code
#

n, k = gets.chomp.split(" ").map{|i| i.to_i}
puts k * (k - 1) ** (n - 1)
