#
# File    : B.rb
# Author  : Kazune Takahashi
# Created : 1/27/2019, 9:02:52 PM
# Powered by Visual Studio Code
#

n = gets.to_i
ary = []
3.times{
  ary << gets.chomp
}
n = ary[0].size
cnt = 0
for i in 0...n
  hash = {}
  for j in 0...3
    c = ary[j][i]
    if hash.has_key?(c)
      hash[c] += 1
    else
      hash[c] = 1
    end
  end
  maxi = hash.values.max
  cnt += 3 - maxi
end
puts cnt
