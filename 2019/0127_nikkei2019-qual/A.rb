#
# File    : A.rb
# Author  : Kazune Takahashi
# Created : 1/27/2019, 9:00:59 PM
# Powered by Visual Studio Code
#

n, a, b = gets.chomp.split(" ").map{|i| i.to_i}

mini = [a + b - n, 0].max
maxi = [a, b].max

puts "#{maxi} #{mini}"