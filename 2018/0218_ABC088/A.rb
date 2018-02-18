#
# File    : A.rb
# Author  : Kazune Takahashi
# Created : 2018-2-18 20:59:12
# Powered by Visual Studio Code
#

n = gets.to_i
a = gets.to_i

if a >= 500
  puts "Yes"
elsif n%500 <= a
  puts "Yes"
else
  puts "No"
end