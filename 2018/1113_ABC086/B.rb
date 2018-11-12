#
# File    : B.rb
# Author  : Kazune Takahashi
# Created : 11/13/2018, 7:47:50 AM
# Powered by Visual Studio Code
#

a, b = gets.chomp.split(" ").map{|i| i.to_s}
n = (a + b).to_i

for i in 0...1000 do
  if n == i ** 2
    puts "Yes"
    exit
  end
end

puts "No"
