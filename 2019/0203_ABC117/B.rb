#
# File    : B.rb
# Author  : Kazune Takahashi
# Created : 2/3/2019, 9:02:53 PM
# Powered by Visual Studio Code
#

n = gets.to_i
l = gets.chomp.split(" ").map{|i| i.to_i}
sum = l.inject(:+)
maxi = l.max
if sum - maxi > maxi
  puts "Yes"
else
  puts "No"
end