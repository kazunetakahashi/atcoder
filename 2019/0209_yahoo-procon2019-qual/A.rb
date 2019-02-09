#
# File    : A.rb
# Author  : Kazune Takahashi
# Created : 2/9/2019, 8:50:44 PM
# Powered by Visual Studio Code
#

n, k = gets.chomp.split(" ").map{|i| i.to_i}
ary = []
for i in 1..n
  if i - ary[-1] > 1
    ary << i
  end
end
if ary.size >= k
  puts "YES"
else
  puts "NO"
end