class Tree
  attr_accessor :zero, :one

  def initialize()
    @zero = nil
    @one = nil
  end
end

n, l = gets.chomp.split(" ").map{|i| i.to_i}
s = []
n.times{
  s << gets.chomp
}

root = Tree.new()

s.each{|str|
  now = root
  str.chars{|c|
    if c == '0'
      if now.zero.nil?
        now.zero = Tree.new()
      end
      now = now.zero
    else
      if now.one.nil?
        now.one = Tree.new()
      end
      now = now.one
    end
  }
}

def cnt(tree)
  if tree.nil?
    return -1
  end
  zero = cnt(tree.zero)
  one = cnt(tree.one)
  return (one+1)^(zero+1)
end

ans = cnt(root)

puts "ans = #{ans}"

if ans == 0
  puts "Bob"
else
  puts "Alice"
end
