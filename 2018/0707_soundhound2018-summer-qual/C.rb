#
# File    : C.rb
# Author  : Kazune Takahashi
# Created : 2018-7-7 21:49:44
# Powered by Visual Studio Code
#

n, m, d = gets.chomp.split(" ").map{|i| i.to_f}

if d >= 1
  ans = 2 * (n - d) * (m - 1) / (n * n)
else
  ans = n * (m - 1) / (n * n);
end

puts sprintf("%.2f", ans)