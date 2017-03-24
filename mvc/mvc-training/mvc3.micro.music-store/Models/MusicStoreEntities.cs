using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Data.Entity;

namespace mvc3.micro.music_store.Models
{
    public class MusicStoreEntities : DbContext
    {
        public DbSet<Album> Albums { get; set; }
        public DbSet<Genre> Genres { get; set; }

        public DbSet<Artist> Artists { get; set; }

        /*
        protected override void OnModelCreating(DbModelBuilder modelBuilder)
        {
            base.OnModelCreating(modelBuilder);

            modelBuilder.Entity<Album>().ToTable("efdemo.Album");//默认情况下，EF 将实体映射到数据库中 dbo 架构下的同名表上，这里我将订单映射到数据库中 efdemo 架构下的 Order 表。
        }
        */
    }
}