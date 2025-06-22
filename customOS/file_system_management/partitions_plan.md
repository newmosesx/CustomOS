Filesystem: Once we have a block device driver (your storage driver), we can implement a filesystem on top of it.

    Recommendation: Start by writing a read-only driver for a simple, well-documented filesystem like FAT32. This will allow you to load programs and data from a real hard drive or USB stick. Later, you can add write support or design your own filesystem.