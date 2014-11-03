use strict;
use warnings;
use feature qw(say);

my $DEBUG = 0;

if ($#ARGV < 1) {
	print "ERROR: no arguments\n";
	say "usage: \"perl move_file.pl filename.cpp SRM600 \"";
	exit(1);
}

my $file_name = $ARGV[0];
my $target_dir = $ARGV[1];
say "Target file name: $file_name";
say "Target directory: $target_dir";

unless (-d "../$target_dir") {
	say "Creating directory: $target_dir";
	mkdir "../$target_dir", 0700 or die "$!:../$target_dir";
}

unless (-f "$file_name") {
    say "ERROR: File $file_name not found";
    exit(1);
}
if (-l "$file_name") {
    say "ERROR: File $file_name is already moved";
    exit(1);
}

my $return_value = system "mv $file_name ../$target_dir/ && ln -s ../$target_dir/$file_name $file_name";

if ($return_value == 0) {
	say "Successfully move file!!";
} else {
	say "ERROR: Failed to move file!!";
}
