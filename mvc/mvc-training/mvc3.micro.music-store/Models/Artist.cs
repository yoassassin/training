using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.ComponentModel.DataAnnotations;

namespace mvc3.micro.music_store.Models
{//refer http://www.cnblogs.com/haogj/archive/2011/05/06/2039149.html
    public class Artist
    {
        [Key]//这里我们强制 OrderNumber 属性作为主键
        [DatabaseGenerated(DatabaseGeneratedOption.Identity)]//而且是一个自增长的列。
        public int ArtistId { get; set; }

        [Required]
        public string Name { get; set; }

        //为什么艺术家这里没有关联的唱片呢？ 应该是rel关系在Album类里就够了
    }
}