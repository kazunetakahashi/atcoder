#
# File    : A.rb
# Author  : Kazune Takahashi
# Created : 2018-9-8 20:58:13
# Powered by Visual Studio Code
#

a, b = gets.chomp.split(" ").map{|i| i.to_i}
if a % 2 == 0 || b % 2 == 0
  puts "No"
else
  puts "Yes"
end