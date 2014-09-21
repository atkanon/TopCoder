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

if (-d "../$target_dir") {
    say "ERROR: Directory $target_dir not found";
    exit(1);
}

if (-f "$file_name") {
    say "ERROR: File $file_name not found";
    exit(1);
}


my $return_value = system "cat file";

if ($return_value == 0) {
	say "Successfully move file!!";
} else {
	say "ERROR: Failed to move file!!";
}
