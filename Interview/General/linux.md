I'll help you prepare for Linux commands that are commonly asked in TCS Digital interviews. Here's a comprehensive guide covering the essential areas:

## Core File and Directory Operations

**Navigation and Listing:**
- `pwd` - Print working directory
- `ls`, `ls -l`, `ls -la` - List files with detailed permissions
- `cd`, `cd ..`, `cd ~` - Change directories
- `find /path -name "filename"` - Search for files
- `locate filename` - Quick file search using database

**File Operations:**
- `cp source dest` - Copy files
- `mv old new` - Move/rename files
- `rm file`, `rm -rf directory` - Remove files/directories
- `mkdir`, `rmdir` - Create/remove directories
- `touch filename` - Create empty file or update timestamp

## Text Processing Commands

**Viewing Files:**
- `cat`, `less`, `more` - Display file contents
- `head -n 10 file`, `tail -n 10 file` - Show first/last lines
- `tail -f logfile` - Follow log files in real-time

**Text Manipulation:**
- `grep "pattern" file` - Search text patterns
- `grep -r "pattern" directory` - Recursive search
- `sed 's/old/new/g' file` - Stream editing
- `awk '{print $1}' file` - Text processing
- `sort file`, `sort -r file` - Sort lines
- `uniq file` - Remove duplicate lines
- `wc -l file` - Count lines, words, characters

## System Information Commands

**Process Management:**
- `ps aux` - List all running processes
- `top`, `htop` - Real-time process monitoring
- `kill PID`, `killall processname` - Terminate processes
- `jobs`, `bg`, `fg` - Job control
- `nohup command &` - Run commands in background

**System Resources:**
- `df -h` - Disk space usage
- `du -sh directory` - Directory size
- `free -h` - Memory usage
- `uptime` - System uptime and load
- `who`, `w` - Currently logged users

## File Permissions and Ownership

**Permission Commands:**
- `chmod 755 file` - Change file permissions
- `chmod u+x file` - Add execute permission for user
- `chown user:group file` - Change ownership
- `umask` - Set default permissions

**Understanding Permissions:**
- `ls -l` output: `-rwxr-xr--` (user/group/others)
- Numeric: 4(read) + 2(write) + 1(execute)

## Network and System Commands

**Network:**
- `ping hostname` - Test connectivity
- `wget URL`, `curl URL` - Download files
- `netstat -tulpn` - Show network connections
- `ssh user@hostname` - Remote login
- `scp file user@host:/path` - Secure copy over network

**System Control:**
- `systemctl start/stop/restart service` - Service management
- `service servicename status` - Check service status
- `crontab -e` - Schedule tasks
- `history` - Command history

## Archive and Compression

**Tar Commands:**
- `tar -czf archive.tar.gz directory/` - Create compressed archive
- `tar -xzf archive.tar.gz` - Extract archive
- `tar -tzf archive.tar.gz` - List archive contents

**Other Compression:**
- `zip -r archive.zip directory/`
- `unzip archive.zip`
- `gzip file`, `gunzip file.gz`

## Advanced Commands for Interviews

**Text Processing Combinations:**
- `ps aux | grep apache` - Find specific processes
- `cat file | sort | uniq -c` - Count unique occurrences
- `find /var/log -name "*.log" -exec grep "error" {} \;` - Complex find operations

**One-liners Often Asked:**
- `find . -type f -name "*.txt" | xargs grep "pattern"` - Search in multiple files
- `awk '{sum+=$1} END {print sum}' file` - Sum a column
- `cut -d',' -f2 file.csv` - Extract CSV columns

## Interview-Specific Scenarios

**Log Analysis:**
```bash
# Find top 10 IP addresses in access log
cat access.log | awk '{print $1}' | sort | uniq -c | sort -nr | head -10

# Monitor disk usage in real-time
watch -n 1 'df -h'
```

**System Troubleshooting:**
```bash
# Check system load and processes
top -bn1 | head -20

# Find large files
find / -type f -size +100M 2>/dev/null

# Check failed login attempts
grep "Failed password" /var/log/auth.log
```

## Tips for TCS Digital Interview

1. **Be ready to explain** what each command does, not just memorize syntax
2. **Practice combining commands** with pipes and redirections
3. **Know the difference** between `>` (overwrite) and `>>` (append)
4. **Understand exit codes** - `$?` shows last command's exit status
5. **Be familiar with vim basics** - `i` (insert), `:wq` (save and quit), `:q!` (quit without saving)

**Common Interview Questions:**
- How to find files modified in last 7 days?
- How to kill all processes of a specific user?
- How to check which ports are listening?
- How to schedule a job to run every day at 2 AM?
- How to find the largest files in a directory?

Practice these commands hands-on, and be prepared to explain practical scenarios where you'd use them in a DevOps or system administration context.