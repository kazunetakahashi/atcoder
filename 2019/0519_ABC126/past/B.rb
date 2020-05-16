#
# File    : B.rb
# Author  : Kazune Takahashi
# Created : 5/19/2019, 9:03:56 PM
# Powered by Visual Studio Code
#

s = gets.chomp

a = s[0...2].to_i
b = s[2...4].to_i

ax = (1 <= a && a <= 12)
bx = (1 <= b && b <= 12)

if ax && bx
  puts "AMBIGUOUS"
elsif ax
  puts "MMYY"
elsif bx
  puts "YYMM"
else
  puts "NA"
end