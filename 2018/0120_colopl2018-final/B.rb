if !ENV['RUBY_THREAD_VM_STACK_SIZE']
	#require 'rbconfig';RUBY=File.join(RbConfig::CONFIG['bindir'],RbConfig::CONFIG['ruby_install_name'])
	require 'rubygems';RUBY=Gem.ruby
	exec({'RUBY_THREAD_VM_STACK_SIZE'=>'100000000'},RUBY,$0)
end

s = gets.chomp

def henkan(str)
  op = str[0]
  if !['+', '-', '*', '/'].include?(op)
    return str
  end
  naka = str[2..-2]
  cnt = 0
  for i in 0...naka.size
    if naka[i] == '('
      cnt += 1
    elsif naka[i] == ')'
      cnt -= 1
    elsif naka[i] == ',' && cnt == 0
      naka[i] = '@'
    end
  end
  ary = naka.split('@')
  for i in 0...ary.size
    ary[i] = henkan(ary[i])
  end
  return '(' + ary.join(op) + ')'
end

puts henkan(s)
