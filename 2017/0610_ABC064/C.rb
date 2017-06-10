n = gets.to_i
a = gets.chomp.split(" ").map{|i| i.to_i}
rate = Array.new(8){0}
other = 0
a.each{|r|
  if r >= 3200
    other += 1
  else
    rate[r/400] += 1
  end
}
color = 0
rate.each{|x|
  if x != 0
    color += 1
  end
}
mini = color
maxi = color + other
if mini == 0 && other > 0
  mini += 1
end
puts "#{mini} #{maxi}"
