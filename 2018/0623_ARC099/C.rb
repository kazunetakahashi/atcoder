#
# File    : C.rb
# Author  : Kazune Takahashi
# Created : 2018-6-23 21:01:02
# Powered by Visual Studio Code
#

n, k = gets.chomp.split(" ").map{|i| i.to_i}
a = gets.chomp.split(" ").map{|i| i.to_i}

ind = 0

for i in 0...a.size
  if (a[i] == 1)
    ind = i
    break
  end
end

puts (n + k - 2) / (k - 1)
