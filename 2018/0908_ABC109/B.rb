#
# File    : B.rb
# Author  : Kazune Takahashi
# Created : 2018-9-8 21:01:53
# Powered by Visual Studio Code
#

n = gets.to_i
w = []
n.times{
  w << gets.chomp
}
dic = {}
dic[w[0]] = true
for i in 0...(n-1)
  if dic[w[i+1]].nil? && w[i][-1] == w[i+1][0]
    dic[w[i+1]] = true
  else
    puts "No"
    exit
  end
end
puts "Yes"
