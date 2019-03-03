#
# File    : B.rb
# Author  : Kazune Takahashi
# Created : 3/3/2019, 9:02:17 PM
# Powered by Visual Studio Code
#

a, b, k = gets.chomp.split(" ").map{|i| i.to_i}

for i in 1..[a, b].max
  if a % i == 0 && b % i == 0
    k -= 1
    p i
  end
  if k == 0
    puts i
    exit
  end
end