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

if (!(-d "../$target_dir")) {
    say "WARNING: Directory $target_dir not found";
    say "creating...";
    my $return_value = system "mkdir ../${target_dir}";
    if ($return_value != 0) {
        say "failed";
        exit(1);
    }
}

if (-f "$file_name") {
    if (system "mv ${file_name} ../${target_dir}") {
        say "error failed to"
    }
} else {
    say "ERROR: File $file_name not found";
    exit(1);
}


my $cat = 'cat';

my $return_value = system "$cat temp.cpp";

if ($return_value == 0) {
	say "Successfully move file!!";
} else {
	say "ERROR: Failed to move file!!";
}
