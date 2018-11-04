#
# File    : C.rb
# Author  : Kazune Takahashi
# Created : 2018-11-4 21:06:08
# Powered by Visual Studio Code
#

n, m = gets.chomp.split(" ").map{|i| i.to_i}
pref = Array.new(n){[]}
for i in 0...m
  pa, y = gets.chomp.split(" ").map{|i| i.to_i}
  pref[pa - 1] << [y, i]
end

ans = []

for i in 0...n
  pref[i].sort!
  for j in 0...pref[i].size
    ans << [pref[i][j][1], (i+1).to_s.rjust(6, "0") + (j+1).to_s.rjust(6, "0")]
  end
end

ans.sort.each{|cnt, a|
  puts a

}