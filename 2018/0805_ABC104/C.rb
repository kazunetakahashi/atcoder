#
# File    : C.rb
# Author  : Kazune Takahashi
# Created : 2018-8-5 21:06:58
# Powered by Visual Studio Code
#

d, g = gets.chomp.split(" ").map{|i| i.to_i}
g /= 100
prob = []
comp = []
d.times{
  x, y = gets.chomp.split(" ").map{|i| i.to_i}
  prob << x
  comp << y/100
}

now = d - 1
score = 0
cnt = 0

while score < g
  while prob[now] > 0
    score += now + 1
    prob[now] -= 1
    cnt += 1
    if score >= g
      puts cnt
      exit
    end
  end
  score += comp[now]
  if score >= g
    puts cnt
    exit
  end
  now -= 1
end