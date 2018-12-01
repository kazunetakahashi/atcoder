#
# File    : B.rb
# Author  : Kazune Takahashi
# Created : 2018-12-1 22:21:49
# Powered by Visual Studio Code
#

n = gets.chomp
x = n.to_i
sum = 0
n.chars{|c|
  sum += c.to_i
}
if x % sum == 0
  puts "Yes"
else
  puts "No"
end