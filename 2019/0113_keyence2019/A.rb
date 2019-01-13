#
# File    : A.rb
# Author  : Kazune Takahashi
# Created : 1/13/2019, 8:32:26 PM
# Powered by Visual Studio Code
#

q = gets.chomp.split(" ").map{|i| i.to_i}.sort
if q == [1, 4, 7, 9]
  puts "Yes"
else
  puts "No"
end